#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "GameFramework/Actor.h"
#include "PostDeath_Params.h"
#include "PostDeathParamsOverride.generated.h"

UCLASS(Blueprintable)
class APostDeathParamsOverride : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseCustomPreset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo Preset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPostDeath_Params CurrentParameters;
    
    APostDeathParamsOverride();
};

