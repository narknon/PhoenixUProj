#pragma once
#include "CoreMinimal.h"
#include "EStencilRulesTypeMode.h"
#include "StencilPrimitiveTypeRules.generated.h"

USTRUCT(BlueprintType)
struct STENCILMANAGER_API FStencilPrimitiveTypeRules {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStencilRulesTypeMode Static;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStencilRulesTypeMode Skeletal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStencilRulesTypeMode Instanced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStencilRulesTypeMode Spline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStencilRulesTypeMode Moveable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStencilRulesTypeMode Stationary;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStencilRulesTypeMode ReceivesDecals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStencilRulesTypeMode ReceivesWeatherDecals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStencilRulesTypeMode RenderCustomDepth;
    
    FStencilPrimitiveTypeRules();
};

