#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SceneRigAnimationRegsitryAnim.h"
#include "SceneRigAnimationRegsitryInheritRegistry.h"
#include "SceneRigAnimationRegistry.generated.h"

UCLASS(Blueprintable)
class USceneRigAnimationRegistry : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSceneRigAnimationRegsitryInheritRegistry> InheritFromRegistries;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSceneRigAnimationRegsitryAnim> Animations;
    
    USceneRigAnimationRegistry();
};

