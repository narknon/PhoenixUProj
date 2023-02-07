#pragma once
#include "CoreMinimal.h"
#include "EMaterialSwapRulesTypeMode.h"
#include "MaterialSwapMeshTypeRules.generated.h"

USTRUCT(BlueprintType)
struct FMaterialSwapMeshTypeRules {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSwapRulesTypeMode Static;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSwapRulesTypeMode Skeletal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSwapRulesTypeMode Instanced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSwapRulesTypeMode Spline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSwapRulesTypeMode Moveable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSwapRulesTypeMode Stationary;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSwapRulesTypeMode ReceivesDecals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSwapRulesTypeMode ReceivesWeatherDecals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSwapRulesTypeMode RenderCustomDepth;
    
    MATERIALPERMUTER_API FMaterialSwapMeshTypeRules();
};

