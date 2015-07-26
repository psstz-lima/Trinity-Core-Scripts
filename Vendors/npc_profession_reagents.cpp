/*
<--------------------------------------------------------------------------->
- Developer(s): InfusionWoW
- Updated By: Ghostcrawler336
- Complete: %0
- ScriptName: 'npc_profession_reagents'
- Comment: N/A
<--------------------------------------------------------------------------->
*/
class multi_profession : public CreatureScript
{
	public:
		multi_profession() : CreatureScript("multi_profession")
		{
		}

		bool OnGossipHello(Player * pPlayer, Creature * pCreature)
		{
			Creature * npc_next = pPlayer->FindNearestCreature(600010, 30.0f, true);
			
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_Drink_27_BlueSoup:24|t|r Cooking", GOSSIP_SENDER_MAIN, 0);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_Fabric_Silk_01:24|t|r Cloth", GOSSIP_SENDER_MAIN, 1);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Trade_Engineering:24|t|r Crafting", GOSSIP_SENDER_MAIN, 2);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_ELEMENTAL_CRYSTAL_EARTH:24|t|r Elemental", GOSSIP_SENDER_MAIN, 3);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_Enchant_AbyssCrystal:24|t|r Enchanting", GOSSIP_SENDER_MAIN, 4);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Trade_Herbalism:24|t|r Herbs", GOSSIP_SENDER_MAIN, 5);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\inv_misc_mastersinscription:24|t|r Inscription", GOSSIP_SENDER_MAIN, 6);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_JEWELCRAFTING_GEM_31:24|t|r Jewelcrafting", GOSSIP_SENDER_MAIN, 7);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Trade_Archaeology_Dwarf_RuneStone:24|t|r Metal & Stone", GOSSIP_SENDER_MAIN, 8);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Trade_LeatherWorking:24|t|r Leather", GOSSIP_SENDER_MAIN, 9);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\spell_magic_lesserinvisibilty:24|t|r Nevermind", GOSSIP_SENDER_MAIN, 10);
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
						m_session->SendListInventory(Creature->GetGUID(), 2500033);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 1:
					{

						m_session->SendListInventory(Creature->GetGUID(), 2500033);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 2:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500033);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 3:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500033);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 4:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500033);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 5:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500033);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 6:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500033);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 7:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500033);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 8:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500033);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 9:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500033);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 10:
					{
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
			}
			return true;
		}

};

void AddSC_multi_profession()
{
	new multi_profession();
}