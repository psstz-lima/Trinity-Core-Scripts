

class npc_support : public CreatureScript
{
    public:
        npc_support() : CreatureScript("npc_support") { }

        bool OnGossipHello(Player* player, Creature* creature)
        {
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "1. Ich kann eine Klassenquest nicht abschliessen.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "2. Ich kann eine Nordend Rufquest nicht abschliessen.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "3. Ich kann eine Normale Quest nicht abschliessen.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "4. Ich habe Probleme nach dem Fraktionswechsel.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "5. Ich sehe den SucheNachGruppe Channel nicht.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "6. Ich habe eine Frage wegen dem Spenden.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "7. Ich habe das falsche Item gespendet.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+7);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "8. Wann werden ArenaPunkte verteilt ?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+8);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "9. Wann sind Wartungsarbeiten?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+9);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "10. Wann sind die Supportzeiten?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+10);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "11. Nach einem Serverdown fehlen mir Items.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+11);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "12. Nach einem Sertverdown funktioniert eine Quest nichtmehr.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+12);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "13. Ein Spieler hat mich beleidigt.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+13);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "14. Eine Instanz geht nicht und wir oder ich komme nicht weiter.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+14);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "15. Ich habe eine Frage die hier nirgends steht.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+15);
				player->PlayerTalkClass->SendGossipMenu(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            return true;
		};

		bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
		{
            player->PlayerTalkClass->ClearMenus();
            player->CLOSE_GOSSIP_MENU();
        switch (action)
            {
		    
			case GOSSIP_ACTION_INFO_DEF+1:
					creature->Whisper("Support Message Here...", LANG_UNIVERSAL, player, false);
	                player->CLOSE_GOSSIP_MENU();
	           break;
			case GOSSIP_ACTION_INFO_DEF+2:
				creature->Whisper("Support Message Here...", LANG_UNIVERSAL, player, false);
	                player->CLOSE_GOSSIP_MENU();
	           break;
			case GOSSIP_ACTION_INFO_DEF+3:
				creature->Whisper("Support Message Here...", LANG_UNIVERSAL, player, false);
	                player->CLOSE_GOSSIP_MENU();
	           break;
			case GOSSIP_ACTION_INFO_DEF+4:
				creature->Whisper("Support Message Here...", LANG_UNIVERSAL, player, false);
	                player->CLOSE_GOSSIP_MENU();
	           break;
			case GOSSIP_ACTION_INFO_DEF+5:
				creature->Whisper("Support Message Here...", LANG_UNIVERSAL, player, false);
	                player->CLOSE_GOSSIP_MENU();
	           break;
			case GOSSIP_ACTION_INFO_DEF+6:
				creature->Whisper("Support Message Here...", LANG_UNIVERSAL, player, false);
	                player->CLOSE_GOSSIP_MENU();
	           break;
			case GOSSIP_ACTION_INFO_DEF+7:
				creature->Whisper("Support Message Here...", LANG_UNIVERSAL, player, false);
	                player->CLOSE_GOSSIP_MENU();
	           break;
			case GOSSIP_ACTION_INFO_DEF+8:
				creature->Whisper("Support Message Here...", LANG_UNIVERSAL, player, false);
	                player->CLOSE_GOSSIP_MENU();
	           break;
			case GOSSIP_ACTION_INFO_DEF+9:
				creature->Whisper("Support Message Here...", LANG_UNIVERSAL, player, false);
	                player->CLOSE_GOSSIP_MENU();
	           break;
			case GOSSIP_ACTION_INFO_DEF+10:
				creature->Whisper("Support Message Here...", LANG_UNIVERSAL, player, false);
	                player->CLOSE_GOSSIP_MENU();
	           break;
			case GOSSIP_ACTION_INFO_DEF+11:
				creature->Whisper("Support Message Here...", LANG_UNIVERSAL, player, false);
	                player->CLOSE_GOSSIP_MENU();
	           break;
			case GOSSIP_ACTION_INFO_DEF+12:
				creature->Whisper("Support Message Here...", LANG_UNIVERSAL, player, false);
	                player->CLOSE_GOSSIP_MENU();
	           break;
			   creature->Whisper("Support Message Here...", LANG_UNIVERSAL, player, false);
			case GOSSIP_ACTION_INFO_DEF+13:
	                player->CLOSE_GOSSIP_MENU();
	           break;
			case GOSSIP_ACTION_INFO_DEF+14:
				creature->Whisper("Support Message Here...", LANG_UNIVERSAL, player, false);
	                player->CLOSE_GOSSIP_MENU();
	           break;
			case GOSSIP_ACTION_INFO_DEF+15:
				creature->Whisper("Support Message Here...", LANG_UNIVERSAL, player, false);
	                player->CLOSE_GOSSIP_MENU();
	           break;
			}

			player->CLOSE_GOSSIP_MENU();
			return true;
	    }		
};

void AddSC_npc_support()
{
	new npc_support();
}
