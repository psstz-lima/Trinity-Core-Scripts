/*
<--------------------------------------------------------------------------->
- Developer(s): InfusionWoW
- Updated By: Ghostcrawler336
- Complete: %0
- ScriptName: 'npc_startergear'
- Comment: N/A
<--------------------------------------------------------------------------->
*/

class multi_startergear : public CreatureScript
{
	public:
		multi_startergear() : CreatureScript("multi_startergear")
		{
		}

		bool OnGossipHello(Player * pPlayer, Creature * pCreature)
		{
			Creature * npc_next = pPlayer->FindNearestCreature(600010, 30.0f, true);
			
			pPlayer->ADD_GOSSIP_ITEM(4, "Yellow", GOSSIP_SENDER_MAIN, 0);
			pPlayer->ADD_GOSSIP_ITEM(4, "Blue", GOSSIP_SENDER_MAIN, 1);
			pPlayer->ADD_GOSSIP_ITEM(4, "Red", GOSSIP_SENDER_MAIN, 2);
			pPlayer->ADD_GOSSIP_ITEM(4, "Purple", GOSSIP_SENDER_MAIN, 3);
			pPlayer->ADD_GOSSIP_ITEM(4, "Orange", GOSSIP_SENDER_MAIN, 4);
			pPlayer->ADD_GOSSIP_ITEM(4, "Nevermind..", GOSSIP_SENDER_MAIN, 4);
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
						m_session->SendListInventory(Creature->GetGUID(), 600010);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 1:
					{

						m_session->SendListInventory(Creature->GetGUID(), 600122);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 2:
					{
						m_session->SendListInventory(Creature->GetGUID(), 6000145);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 3:
					{
						m_session->SendListInventory(Creature->GetGUID(), 6000145);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				
				case 4: // Close Gossips
					{
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
			}
			return true;
		}

};

void AddSC_multi_startergear()
{
	new multi_startergear();
}