/*
<--------------------------------------------------------------------------->
- Developer(s): InfusionWoW
- Updated By: Ghostcrawler336
- Complete: %0
- ScriptName: 'npc_gem'
- Comment: N/A
<--------------------------------------------------------------------------->
*/
class multi_gem : public CreatureScript
{
	public:
		multi_gem() : CreatureScript("multi_gem")
		{
		}

		bool OnGossipHello(Player * pPlayer, Creature * pCreature)
		{
			Creature * npc_next = pPlayer->FindNearestCreature(600010, 30.0f, true);
			
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_JEWELCRAFTING_GEM_38:24|t|r Yellow", GOSSIP_SENDER_MAIN, 0);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_JEWELCRAFTING_GEM_42:24|t|r Blue", GOSSIP_SENDER_MAIN, 1);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_JEWELCRAFTING_GEM_37:24|t|r Red", GOSSIP_SENDER_MAIN, 2);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_JEWELCRAFTING_GEM_40:24|t|r Purple", GOSSIP_SENDER_MAIN, 3);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_JEWELCRAFTING_GEM_41:24|t|r Green", GOSSIP_SENDER_MAIN, 4);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_JEWELCRAFTING_GEM_39:24|t|r Orange", GOSSIP_SENDER_MAIN, 5);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_JEWELCRAFTING_GEM_31:24|t|r Meta", GOSSIP_SENDER_MAIN, 6);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\spell_magic_lesserinvisibilty:24|t|r Nevermind", GOSSIP_SENDER_MAIN, 7);
			pPlayer->PlayerTalkClass->SendGossipMenu(9425, pCreature->GetGUID());
			return true;
		}

		bool OnGossipSelect(Player * Player, Creature * Creature, uint32 /*uiSender*/, uint32 uiAction)
		{
			if(!Player)
				return true;
			
			WorldSession * m_session = Player->GetSession();
			
			switch(uiAction)
			{
				case 0:
					{
						m_session->SendListInventory(Creature->GetGUID(), 500112);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 1:
					{

						m_session->SendListInventory(Creature->GetGUID(), 500113);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 2:
					{
						m_session->SendListInventory(Creature->GetGUID(), 500114);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 3:
					{
						m_session->SendListInventory(Creature->GetGUID(), 500115);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 4:
					{
						m_session->SendListInventory(Creature->GetGUID(), 500116);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 5:
					{
						m_session->SendListInventory(Creature->GetGUID(), 500117);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 6:
					{
						m_session->SendListInventory(Creature->GetGUID(), 500118);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 7: // Close Gossips
					{
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
			}
			return true;
		}

};

void AddSC_multi_gem()
{
	new multi_gem();
}