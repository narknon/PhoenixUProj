#pragma once
#include "CoreMinimal.h"
#include "SceneRigAnimationRegsitryAnim.generated.h"



USTRUCT(BlueprintType)
struct FSceneRigAnimationRegsitryAnim {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LookupKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SelectionWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationAsset* UnrealAnimationAsset;
    
    SCENERIG_API FSceneRigAnimationRegsitryAnim();
};

