/*
Para ser considerada uma associação:
    O objeto associado(membro) não possui qualquer outra relação com o obj(classe);
    O objeto associado(membro) pode pertencer a mais de um objeto(classe) simultaneamente.
    O objeto associado(membro) não tem sua existência gerenciado pelo obj(classe);
    O objeto associado(membro) pode ou não ter conhecimento da existência do obj(classe)

    Na associação obj associado não tem nenhuma relação com o obj em si.
    Ele também pode ser unidirecional ou bidirecional(onde ambos tem conhecimento um do outro).
    
    A relação entre médicos e pacientes é um bom exemplo. 
    O médico tem relação com os pacientes, mas não se trata de uma relação parte/todo.
    um médico pode atender muitos pacientes em um dia. E um paciente pode consultar muitos
    médicos.
    O médico usa o paciente(para obter renda). O paciente usa o médico(para quaisquers fins de saúde que necessite.)
*/

#include <functional>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Patient;

class Doctor
{
private:
    std::string m_name{};
    std::vector<std::reference_wrapper<const Patient>> m_patient{};

public:
    Doctor(std::string_view name) : m_name{name} {}

    void addPatient(Patient &patient);

    friend std::ostream &operator<<(std::ostream &out, const Doctor &doctor);

    const std::string &getName() const { return m_name; }
};

class Patient
{
private:
    std::string m_name{};
    std::vector<std::reference_wrapper<const Doctor>> m_doctor{};

    void addDoctor(const Doctor &doctor)
    {
        m_doctor.push_back(doctor);
    }

public:
    Patient(std::string_view name)
        : m_name{name} {}

    friend std::ostream &operator<<(std::ostream &out, const Patient &patient);

    const std::string &getName() const { return m_name; }

    friend void Doctor::addPatient(Patient &patient);
};

void Doctor::addPatient(Patient &patient)
{
    m_patient.push_back(patient);
    patient.addDoctor(*this);
}

std::ostream &operator<<(std::ostream &out, const Doctor &doctor)
{
    if (doctor.m_patient.empty())
    {
        out << doctor.m_name << "has no patients right now";
        return out;
    }

    out << doctor.m_name << "is seing patients: ";
    for (const auto &patient : doctor.m_patient)
        out << patient.get().getName() << ' ';

    return out;
}

std::ostream &operator<<(std::ostream &out, const Patient &patient)
{
    if (patient.m_doctor.empty())
    {
        out << patient.getName() << "has no doctors right now";
        return out;
    }

    out << patient.m_name << "is seeing doctors: ";
    for (const auto &doctor : patient.m_doctor)
        out << doctor.get().getName() << ' ';
    
    return out;
}

int main(){
    Patient dave {"dave"};
    Patient frank{"frank"};
    Patient betsy{"betsy"};

    Doctor james{"James"};
    Doctor scott{"Scott"};

    james.addPatient(dave);
    
    scott.addPatient(dave);
    scott.addPatient(betsy);

    std::cout << james << '\n';
    std::cout << scott << '\n';
    std::cout << dave << '\n';
    std::cout << frank << '\n';
    std::cout << betsy << '\n';

    return 0;
}

/*
ASSOCIAÇÃO REFLEXIVA:

As vezes os objetos podem ter uma relação com outros objetos do mesmo tipo. Isso é 
chamado de associação reflexiva. Um bom exemplo de associação reflexiva é a relação entre 
um disciplina universitária e seus pré resiquistos (que também são disciplinas universitárias);
*/