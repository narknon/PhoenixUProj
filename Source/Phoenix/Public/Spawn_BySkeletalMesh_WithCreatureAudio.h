#pragma once
#include "CoreMinimal.h"
#include "Spawn_BySkeletalMesh.h"
#include "Spawn_BySkeletalMesh_WithCreatureAudio.generated.h"

class UObjectArchitectAsset;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USpawn_BySkeletalMesh_WithCreatureAudio : public USpawn_BySkeletalMesh {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObjectArchitectAsset* CreatureAudioAsset;
    
    USpawn_BySkeletalMesh_WithCreatureAudio();
};

