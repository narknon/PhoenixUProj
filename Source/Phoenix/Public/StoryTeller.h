#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitect_ComponentOwnerInterface.h"
#include "UObject/Object.h"
#include "StoryTeller.generated.h"

class UBaseArchitectAsset;
class USceneRigProvider;
class USceneRigStory;

UCLASS(Blueprintable, EditInlineNew)
class UStoryTeller : public UObject, public IAnimationArchitect_ComponentOwnerInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneRigProvider* SceneRigProvider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBaseArchitectAsset* LookupAsset;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USceneRigStory*> Stories;
    
public:
    UStoryTeller();
    
    // Fix for true pure virtual functions not being implemented
};

