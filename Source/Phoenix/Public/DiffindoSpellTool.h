#pragma once
#include "CoreMinimal.h"
#include "SpellTool.h"
#include "Templates/SubclassOf.h"
#include "DiffindoSpellTool.generated.h"

class AMunitionType_Base;

UCLASS(Blueprintable)
class ADiffindoSpellTool : public ASpellTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ProjectileTargetHalfAngleXY;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ProjectileTargetHalfAngleZ;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool TargetObjects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AMunitionType_Base> UpgradedMunitionActor;
    
    ADiffindoSpellTool(const FObjectInitializer& ObjectInitializer);
};

