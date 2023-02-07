#pragma once
#include "CoreMinimal.h"
#include "EMaterialSwapRulesTypeMode.h"
#include "MaterialSwapActorTypeRules.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialSwapActorTypeRules {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSwapRulesTypeMode Players;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSwapRulesTypeMode Characters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSwapRulesTypeMode Pawns;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSwapRulesTypeMode Moveable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSwapRulesTypeMode Stationary;
    
    FMaterialSwapActorTypeRules();
};

