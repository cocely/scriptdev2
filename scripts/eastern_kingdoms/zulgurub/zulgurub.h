/* Copyright (C) 2006 - 2013 ScriptDev2 <http://www.scriptdev2.com/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_ZULGURUB_H
#define DEF_ZULGURUB_H

enum
{
    MAX_ENCOUNTER           = 8,
    MAX_PRIESTS             = 5,

    TYPE_JEKLIK             = 0,
    TYPE_VENOXIS            = 1,
    TYPE_MARLI              = 2,
    TYPE_THEKAL             = 3,
    TYPE_ARLOKK             = 4,
    TYPE_OHGAN              = 5,                            // Do not change, used by Acid
    TYPE_LORKHAN            = 6,
    TYPE_ZATH               = 7,

    NPC_LORKHAN             = 11347,
    NPC_ZATH                = 11348,
    NPC_THEKAL              = 14509,
    NPC_JINDO               = 11380,
    NPC_HAKKAR              = 14834,
    NPC_PANTHER_TRIGGER     = 15091,
    NPC_BLOODLORD_MANDOKIR  = 11382,
    NPC_MARLI               = 14510,

    GO_SPIDER_EGG           = 179985,
    GO_GONG_OF_BETHEKK      = 180526,
    GO_FORCEFIELD           = 180497,

    SAY_MINION_DESTROY      = -1309022,
    SAY_HAKKAR_PROTECT      = -1309023,

    HP_LOSS_PER_PRIEST      = 60000,

    AREATRIGGER_ENTER       = 3958,
    AREATRIGGER_ALTAR       = 3960,
};

static const float aMandokirDownstairsPos[3] = {-12196.30f, -1948.37f, 130.31f};

class MANGOS_DLL_DECL instance_zulgurub : public ScriptedInstance
{
    public:
        instance_zulgurub(Map* pMap);
        ~instance_zulgurub() {}

        void Initialize();
        // IsEncounterInProgress() const { return false; }  // not active in Zul'Gurub

        void OnCreatureCreate(Creature* pCreature);
        void OnObjectCreate(GameObject* pGo);

        void SetData(uint32 uiType, uint32 uiData);
        uint32 GetData(uint32 uiType);

        const char* Save() { return m_strInstData.c_str(); }
        void Load(const char* chrIn);

        void DoYellAtTriggerIfCan(uint32 uiTriggerId);

        Creature* SelectRandomPantherTrigger(bool bIsLeft);

    protected:
        void DoLowerHakkarHitPoints();

        uint32 m_auiEncounter[MAX_ENCOUNTER];
        std::string m_strInstData;

        GuidList m_lRightPantherTriggerGuidList;
        GuidList m_lLeftPantherTriggerGuidList;
        GuidList m_lSpiderEggGuidList;

        bool m_bHasIntroYelled;
        bool m_bHasAltarYelled;
};

#endif
