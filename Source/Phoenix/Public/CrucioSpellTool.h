#pragma once
#include "CoreMinimal.h"
#include "FireOnceSpellTool.h"
#include "Templates/SubclassOf.h"
#include "CrucioSpellTool.generated.h"

class AMunitionType_Base;
class UMultiFX2_Base;

UCLASS(Blueprintable)
class ACrucioSpellTool : public AFireOnceSpellTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> DamageFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TalentProjectileDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TalentProjectileIgnoreNearDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TalentProjectileDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TalentProjectileRandomHalfAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AMunitionType_Base> TalentProjectileMunition;
    
    ACrucioSpellTool(const FObjectInitializer& ObjectInitializer);
};

