#include "SpellCasterTool.h"
#include "ToolSetComponent.h"

class AActor;
class AMunitionType_Base;
class USpellToolRecord;

void ASpellCasterTool::StopSpell(AMunitionType_Base* InMunition) {
}

void ASpellCasterTool::CastSpell(USpellToolRecord* SpellToolRecord, AActor* Target, FVector InSourceLocation, const FRotator& Orientation, float AccuracyOffset, float InObjDamage, float InCharDamage, bool bAffectTarget, float SpellTime, int32 SpellLevel, const bool bAlwaysHitTargetActor, bool bVelocityIncludeTarget, bool bUnblockableAgainstPlayer, EEnemyShieldBreaker UnblockableLByNPCLevel) {
}

ASpellCasterTool::ASpellCasterTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ToolSetComponent = CreateDefaultSubobject<UToolSetComponent>(TEXT("Spell Tools"));
}

