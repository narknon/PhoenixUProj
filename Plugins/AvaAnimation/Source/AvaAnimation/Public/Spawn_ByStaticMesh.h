#pragma once
#include "CoreMinimal.h"
#include "ActorSpawner.h"
#include "Spawn_ByStaticMesh.generated.h"

class USpawnByPrimitiveOptions;
class UStaticMesh;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API USpawn_ByStaticMesh : public UActorSpawner {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* StaticMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LODOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USpawnByPrimitiveOptions*> PrimitiveOptions;
    
    USpawn_ByStaticMesh();
};

