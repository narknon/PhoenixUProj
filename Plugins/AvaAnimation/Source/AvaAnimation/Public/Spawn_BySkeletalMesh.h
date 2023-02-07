#pragma once
#include "CoreMinimal.h"
#include "ActorSpawner.h"
#include "Spawn_BySkeletalMesh.generated.h"

class USkeletalMesh;
class USpawnByPrimitiveOptions;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API USpawn_BySkeletalMesh : public UActorSpawner {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* SkeletalMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LODOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USpawnByPrimitiveOptions*> PrimitiveOptions;
    
    USpawn_BySkeletalMesh();
};

