#pragma once
#include "CoreMinimal.h"
#include "SceneRigParameterBinding_FString.h"
#include "ActionParameter_FString.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FActionParameter_FString {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigParameterBinding_FString BoundParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DefaultValue;
    
    FActionParameter_FString();
};

