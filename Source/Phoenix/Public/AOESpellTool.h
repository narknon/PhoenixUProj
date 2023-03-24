#pragma once
#include "CoreMinimal.h"
#include "SpellTool.h"
#include "Templates/SubclassOf.h"
#include "AOESpellTool.generated.h"

class AMunitionType_Base;

UCLASS(Blueprintable)
class AAOESpellTool : public ASpellTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTargetCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTargetObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayOnGround;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NoTargetDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AMunitionType_Base> AOEMunition;
    
    AAOESpellTool(const FObjectInitializer& ObjectInitializer);
};

