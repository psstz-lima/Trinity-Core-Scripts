

class player_assistant : public CreatureScript
{
public:
    player_assistant() : CreatureScript("player_assistant") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pPlayer->IsInCombat())
        {
            pPlayer->GetSession()->SendNotification("You are in combat");
            return false;
        }
        pPlayer->GetSession()->SendNotification("Welcome to the Player Assistant");
        pPlayer->ADD_GOSSIP_ITEM(5, "Give me Soul Shards", GOSSIP_SENDER_MAIN, 1);
        pPlayer->ADD_GOSSIP_ITEM(5, "Give me some Refreshments", GOSSIP_SENDER_MAIN, 2);
        pPlayer->ADD_GOSSIP_ITEM(5, "Give me a Mana Gem", GOSSIP_SENDER_MAIN, 3);
        pPlayer->ADD_GOSSIP_ITEM(5, "Reset my talent points", GOSSIP_SENDER_MAIN, 4);
        pPlayer->ADD_GOSSIP_ITEM(5, "Reset my Mount's and Spells ", GOSSIP_SENDER_MAIN, 5);
        pPlayer->ADD_GOSSIP_ITEM(5, "Reset my honor", GOSSIP_SENDER_MAIN, 6);
        pPlayer->ADD_GOSSIP_ITEM(5, "Reset my gold", GOSSIP_SENDER_MAIN, 7);
        pPlayer->ADD_GOSSIP_ITEM(5, "Heal me please", GOSSIP_SENDER_MAIN, 8);
        pPlayer->ADD_GOSSIP_ITEM(7, "Close", GOSSIP_SENDER_MAIN, 9);
        pPlayer->SEND_GOSSIP_MENU(907, pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();

        switch (uiAction)
        {
          case 1:
              {
                  pPlayer->CLOSE_GOSSIP_MENU();
                  pPlayer->CastSpell(pPlayer,24827,false);
				  pCreature->Whisper("Soul Shard Created.", LANG_UNIVERSAL, pPlayer, true);
              }break;
          case 2:
              {
                  pPlayer->CLOSE_GOSSIP_MENU();
                  pPlayer->CastSpell(pPlayer,42956,false);
				  pCreature->Whisper("Refreshments Created.", LANG_UNIVERSAL, pPlayer, true);
              }break;
          case 3:
              {
                  pPlayer->CLOSE_GOSSIP_MENU();
                  pPlayer->CastSpell(pPlayer,42985,false);;
				  pCreature->Whisper("Mana Gem Created", LANG_UNIVERSAL, pPlayer, true);
              }break;
         case 4:
              {
                  pPlayer->CLOSE_GOSSIP_MENU();
                  pPlayer->ResetTalents(true);
				  pCreature->Whisper("Your talents has been reset.", LANG_UNIVERSAL, pPlayer, true);
              }break;
         case 5:
              {
                  pPlayer->CLOSE_GOSSIP_MENU();
                  pPlayer->ResetSpells(false);
				  pCreature->Whisper("Your spells has been reset.", LANG_UNIVERSAL, pPlayer, true);
              }break;
         case 6:
              {
                  pPlayer->CLOSE_GOSSIP_MENU();
                  pPlayer->SetHonorPoints(0);
				  pCreature->Whisper("Your honor has been reset.", LANG_UNIVERSAL, pPlayer, true);
              }break;
         case 7:
              {
                  pPlayer->CLOSE_GOSSIP_MENU();
                  pPlayer->SetMoney(0);
				  pCreature->Whisper("Your gold has been reset.", LANG_UNIVERSAL, pPlayer, true);
              }break;
         case 8:
              {
                  pPlayer->CLOSE_GOSSIP_MENU();
                  pCreature->CastSpell(pPlayer,38588,false);
				  pCreature->Whisper("You have been healed.", LANG_UNIVERSAL, pPlayer, true);
              }break;
         case 9:
              {
                  pPlayer->CLOSE_GOSSIP_MENU();
                return true;
              }break;
        }
        pPlayer->CLOSE_GOSSIP_MENU();
        return true;
    }

};

void AddSC_player_assistant()
{
    new player_assistant();
}