namespace Monster
{

    enum MonsterType
    {
        Orc,
        Globin,
        Troll,
        Ogro,
        Esqueleto,
    };

}
int main()
{
    [[maybe_unsued]]Monster::MonsterType monster{Monster::Ogro};
}