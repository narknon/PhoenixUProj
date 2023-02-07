#pragma once
#include "CoreMinimal.h"
#include "ActorSpawner.h"
#include "Spawn_ByStationStoryContent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USpawn_ByStationStoryContent : public UActorSpawner {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CharacterIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString StoryContentParameter;
    
    USpawn_ByStationStoryContent();
};

