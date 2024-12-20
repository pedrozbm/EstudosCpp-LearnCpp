#include "./Project/include/application.hpp"

uint16 timer_pulso_valvula_tanque_escorva_u16     = 0;
uint16 timer_pulso_off_valvula_tanque_escorva_u16 = 0;

STATUS_TANQUE_ESCORVA STATUS_CONTROLE_RPM_TANQUE_ESCORVA = STATUS_TANQUE_ESCORVA_INICIA_CONTROLE;

void controle_de_rpm_por_succao_tanque_escorva() {
    switch (STATUS_CONTROLE_RPM_TANQUE_ESCORVA) {
    case STATUS_TANQUE_ESCORVA_INICIA_CONTROLE:
        inicializar_controle_rpm_tanque_escorva();
        STATUS_CONTROLE_RPM_TANQUE_ESCORVA = STATUS_TANQUE_ESCORVA_AGUARDA_SETPOINT_RPM;
        break;
    case STATUS_TANQUE_ESCORVA_AGUARDA_SETPOINT_RPM:
        break;
    case STATUS_TANQUE_ESCORVA_AGUARDA_POSSIVEL_INCREMENTO:
        break;
    case STATUS_TANQUE_ESCORVA_ACELERA_MOTOR:
        break;
    case STATUS_TANQUE_ESCORVA_ABERTURA_VALVULA_INICIAL:
        break;
    case STATUS_TANQUE_ESCORVA_ESPERA_ABERTURA_VALVULA:
        break;
    case STATUS_TANQUE_ESCORVA_COMPLETA_ABERTURA_VALVULA:
        break;
    case STATUS_TANQUE_ESCORVA_AGUARDA_FEEDBACK:
        break;
    case STATUS_TANQUE_ESCORVA_FEEDBACK_SUCESSO:
        break;
    case STATUS_TANQUE_ESCORVA_FEEDBACK_ERRO:
        break;
    case STATUS_TANQUE_ESCORVA_CONTROLE_RPM:
        break;
    case STATUS_TANQUE_ESCORVA_FINALIZA_CONTROLE:
        break;
    }
}

void inicializar_controle_rpm_tanque_escorva() {
    fecha_valvula_ao_voltar_controle_b             = false;
    aceleracao_digital_b                           = liga_desliga_aceleracao_digital_b;
    aceleracao_analogico_b                         = liga_desliga_aceleracao_analogica_b;
    tolerancia_incremento_de_aceleracao_digital_u8 = tolerancia_incremento_aceleracao_via_tablet_u8;
    tolerancia_decremento_de_aceleracao_digital_u8 = tolerancia_decremento_aceleracao_via_tablet_u8;
    comando_remoto_controle_por_velocidade_b       = false;
    valvula_atuando_nos_controles();
    timeout_controle_de_velocidade();
    if (iniciando_controle_rpm_remotamente_b == true) {
        alvo_rpm_u16                         = auxiliar_controle_rpm_remoto_u16;
        iniciando_controle_rpm_remotamente_b = false;
    }
}
void ajustar_rpm_velocidade_tanque_escorva() {
    if ((aumenta_rpm_b) && (alvo_rpm_u16 < valor_considerado_rpm_maximo_u16) && (auxiliar_de_botao_aumento_de_alvo_b == false)) {
        alvo_rpm_u16 += controle_de_velocidade_incremento_alvo_u8;
        auxiliar_de_botao_aumento_de_alvo_b = true;
        iniciar_rotina_de_feedback_velocidade_tanque_escorva(COMANDO_ATUALIZAR_VELOCIDADE_LOCAL, NENHUM_COMANDO_REMOTO);
    } else if ((diminui_rpm_b) && (alvo_rpm_u16 > valor_considerado_rpm_minimo_u16) && (auxiliar_de_botao_diminuir_de_alvo_b == false)) {
        alvo_rpm_u16 -= controle_de_velocidade_decremento_alvo_u8;
        auxiliar_de_botao_diminuir_de_alvo_b = true;
        iniciar_rotina_de_feedback_velocidade_tanque_escorva(COMANDO_ATUALIZAR_VELOCIDADE_LOCAL, NENHUM_COMANDO_REMOTO);
    }
    if ((STATUS_COMANDO_REMOTO == COMANDO_ATUALIZAR_VELOCIDADE_REMOTO) && (bloqueio_comando_remoto_atualizar_velocidade_b == true) && (espera_para_comandos_satelital_b == false)) {
        alvo_rpm_u16                                   = auxiliar_rpm_comando_remoto_u16;
        bloqueio_comando_remoto_atualizar_velocidade_b = false;
        iniciar_rotina_de_feedback_velocidade_tanque_escorva(NENHUM_COMANDO_LOCAL, COMANDO_ATUALIZAR_VELOCIDADE_REMOTO);
    }
}
void aguardar_abertura_valvula_velocidade_tanque_escorva() {
    if (!status_valvula_aberta_lido_b) {
        if (timer_pulso_valvula_tanque_escorva_u16 < tempo_valvula_pulso_u16) {
            valvula_atuando_nos_controles();
            timer_pulso_valvula_tanque_escorva_u16 += CYCLE_TIME_MS;
        }
        if (timer_pulso_valvula_tanque_escorva_u16 >= tempo_valvula_pulso_u16 && timer_pulso_off_valvula_tanque_escorva_u16 < tempo_valvula_pulso_off_u16) {
            timer_pulso_off_valvula_tanque_escorva_u16 += CYCLE_TIME_MS;
        }
        if (timer_pulso_off_valvula_tanque_escorva_u16 >= tempo_valvula_pulso_off_u16) {
            timer_pulso_valvula_tanque_escorva_u16     = 0;
            timer_pulso_off_valvula_tanque_escorva_u16 = 0;
            if (status_valvula_aberta_lido_b) {
                status_controle_velocidade_tanque_escorva = STATUS_AGUARDANDO_FEEDBACK;
            }
        }
    } else {
        status_controle_velocidade_tanque_escorva = STATUS_AGUARDANDO_FEEDBACK;
    }
}
void verificar_feedback_velocidade_tanque_escorva() {
    if ((saida_filtro_velocidade_motor_rpm_u16 <= alvo_rpm_u16 + tolerancia_incremento_de_aceleracao_digital_u8) &&
        (saida_filtro_velocidade_motor_rpm_u16 >= alvo_rpm_u16 - tolerancia_decremento_de_aceleracao_digital_u8)) {
        status_de_comandos_do_feedback = FEEDBACK_COMANDO_SUCESSO;
        // Controle da sinalização da motobomba conforme o modo de operação
        if ((STATUS_COMANDO_REMOTO == NENHUM_COMANDO_REMOTO) && (alerta_existente_b == false)) {
            controle_de_sinalizacao_motobomba(MOTOBOMBA_CONECT, 1, MODO_ROTINA_LOCAL);
        } else if ((STATUS_COMANDO_LOCAL == NENHUM_COMANDO_LOCAL) && (alerta_existente_b == false)) {
            controle_de_sinalizacao_motobomba(MOTOBOMBA_CONECT, 1, MODO_ROTINA_REMOTA);
        } else if (alerta_existente_b == true) {
            controle_de_sinalizacao_motobomba(MOTOBOMBA_CONECT, 1, ALERTAS);
        }
        // Estabilização da mensagem de feedback
        if (Timer_estabilizar_geracao_de_mensagem_u16 <= 100) {
            timer_final_de_controle_u16               = valor_de_timer_final_de_controle_u16;
            etapa_final_de_controle_b                 = false;
            Timer_estabilizar_geracao_de_mensagem_u16 = 0;
        }
        Timer_estabilizar_geracao_de_mensagem_u16 += CYCLE_TIME_MS;
    } else {
        // Verificação se o timer de controle finalizou antes de erro
        if (timer_final_de_controle_u16 >= valor_de_timer_final_de_controle_u16) {
            if ((saida_filtro_velocidade_motor_rpm_u16 <= alvo_rpm_u16 + tolerancia_incremento_de_aceleracao_digital_u8) &&
                (saida_filtro_velocidade_motor_rpm_u16 >= alvo_rpm_u16 - tolerancia_decremento_de_aceleracao_digital_u8)) {
                status_de_comandos_do_feedback = FEEDBACK_COMANDO_SUCESSO;
                if ((STATUS_COMANDO_REMOTO == NENHUM_COMANDO_REMOTO) && (alerta_existente_b == false)) {
                    controle_de_sinalizacao_motobomba(MOTOBOMBA_CONECT, 1, MODO_ROTINA_LOCAL);
                } else if ((STATUS_COMANDO_LOCAL == NENHUM_COMANDO_LOCAL) && (alerta_existente_b == false)) {
                    controle_de_sinalizacao_motobomba(MOTOBOMBA_CONECT, 1, MODO_ROTINA_REMOTA);
                } else if (alerta_existente_b == true) {
                    controle_de_sinalizacao_motobomba(MOTOBOMBA_CONECT, 1, ALERTAS);
                }
            } else {
                // Se o RPM não está na faixa de tolerância após o tempo final
                solicitacao_de_controle_velocidade_b      = false;
                solicitacao_controle_de_pressao_b         = false;
                STATUS_CONTROLE_FUNCIONAMENTO_DO_MOTOR    = MARCHA_LENTA;
                status_de_comandos_do_feedback            = FEEDBACK_COMANDO_ERRO;
                status_controle_velocidade_tanque_escorva = STATUS_INICIALIZANDO_CONTROLE;
            }
            etapa_final_de_controle_b   = false;
            timer_final_de_controle_u16 = 0;
        }
        timer_final_de_controle_u16 += CYCLE_TIME_MS;
    }
}
void finalizar_controle_sucesso_velocidade_tanque_escorva() {
    controle_de_sinalizacao_motobomba(MOTOBOMBA_CONECT, 1, MODO_ROTINA_LOCAL);
    solicitacao_de_controle_velocidade_b = false;
}
void tratar_erro_controle_velocidade_tanque_escorva() {
    status_de_comandos_do_feedback       = FEEDBACK_COMANDO_ERRO;
    solicitacao_de_controle_velocidade_b = false;
}

void iniciar_rotina_de_feedback_velocidade_tanque_escorva(uint8_t status_comando_local_u8, uint8_t status_comando_remoto_u8) {
    if (inciando_rotina_de_controle_motobomba_b == false) {
        identificador_de_comandos_do_feedback                              = FEEDBACK_COMANDO_ATUALIZAR_VELOCIDADE;
        status_de_comandos_do_feedback                                     = FEEDBACK_COMANDO_INICIADO;
        STATUS_COMANDO_LOCAL                                               = status_comando_local_u8;
        STATUS_COMANDO_REMOTO                                              = status_comando_remoto_u8;
        timer_de_espera_de_rotina_fora_de_inicio_de_controle_u16           = tempo_de_espera;
        inciando_rotina_de_controle_motobomba_fora_de_inicio_de_controle_b = true;
    } else {
        timer_de_espera_de_rotina_u16 = tempo_de_espera;
    }
}
bool verificar_rpm_atingido_velocidade_tanque_escorva() {
    return (saida_filtro_velocidade_motor_rpm_u16 <= alvo_rpm_u16 + tolerancia_incremento_de_aceleracao_digital_u8) &&
           (saida_filtro_velocidade_motor_rpm_u16 >= alvo_rpm_u16 - tolerancia_decremento_de_aceleracao_digital_u8);
}

void finalizar_controle_velocidade_tanque_escorva() {
    etapa_final_de_controle_b = false;
}