#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "EEnemyShieldBreaker.h"
#include "ItemTool.h"
#include "SpellCasterTool.generated.h"

class AActor;
class AMunitionType_Base;
class ASpellTool;
class USpellToolRecord;
class UToolSetComponent;

UCLASS(Blueprintable)
class ASpellCasterTool : public AItemTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector AttachOffset;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UToolSetComponent* ToolSetComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<USpellToolRecord*, ASpellTool*> SpellToolMap;
    
public:
    ASpellCasterTool();
    UFUNCTION(BlueprintCallable)
    void StopSpell(AMunitionType_Base* InMunition);
    
    UFUNCTION(BlueprintCallable)
    void CastSpell(USpellToolRecord* SpellToolRecord, AActor* Target, FVector InSourceLocation, const FRotator& Orientation, float AccuracyOffset, float InObjDamage, float InCharDamage, bool bAffectTarget, float SpellTime, int32 SpellLevel, const bool bAlwaysHitTargetActor, bool bVelocityIncludeTarget, bool bUnblockableAgainstPlayer, EEnemyShieldBreaker UnblockableLByNPCLevel);
    
};

