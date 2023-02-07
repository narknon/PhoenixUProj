#pragma once
#include "CoreMinimal.h"
#include "SceneRigStory.h"
#include "StationStory.generated.h"

class UAnimationSet_TagLookup;

UCLASS(Blueprintable)
class PHOENIX_API UStationStory : public USceneRigStory {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationSet_TagLookup* AnimationSetProvider;
    
public:
    UStationStory();
};

