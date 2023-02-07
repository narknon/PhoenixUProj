#pragma once
#include "CoreMinimal.h"
#include "SceneRigAnimationRegsitryInheritRegistry.generated.h"

class USceneRigAnimationRegistry;

USTRUCT(BlueprintType)
struct FSceneRigAnimationRegsitryInheritRegistry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LookupKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigAnimationRegistry* InheritFromRegistry;
    
    SCENERIG_API FSceneRigAnimationRegsitryInheritRegistry();
};

