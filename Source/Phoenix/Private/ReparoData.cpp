#include "ReparoData.h"

UReparoData::UReparoData() {
    this->RepairTime = 3.33f;
    this->DelayBetweenChunks = 0.10f;
    this->ScaleDelayBasedOnChunkZ = false;
    this->ScaleDelayBasedOnDistanceFromPoint = false;
    this->DiminishDelay = true;
    this->MaxDelayBetweenSpells = 0.50f;
    this->RepairChunkParticleSystem = NULL;
    this->RepairChunkNiagaraVfx = NULL;
    this->SmallRepairChunkParticleSystem = NULL;
    this->SmallRepairChunkNiagaraVfx = NULL;
    this->SmallChunkSize = 25.00f;
    this->ChunkParticleProbability = 1.00f;
    this->RepairSfx = NULL;
    this->RepairAlmostCompleteTime = 1.00f;
    this->RepairAlmostCompleteSfx = NULL;
    this->RepairSwapParticleSystem = NULL;
    this->RepairSwapNiagaraVfx = NULL;
    this->RepairCompleteSfx = NULL;
    this->EaseForRepairParticles = 1.00f;
    this->SpellTranslate = NULL;
    this->SpellScale = NULL;
    this->SpellRotate = NULL;
    this->ChunkEase = NULL;
    this->EaseResultsScale = NULL;
    this->RepeatCurveOverDistance = false;
    this->RepeatDistance = 100.00f;
    this->ScaleDistanceBasedOnChunkSize = false;
    this->ReferenceChunkSize = 100.00f;
    this->ChunkTranslate = NULL;
    this->ChunkScale = NULL;
    this->ChunkRotate = NULL;
}

