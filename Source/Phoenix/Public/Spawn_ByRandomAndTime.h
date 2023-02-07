#pragma once
#include "CoreMinimal.h"
#include "ActorSpawner.h"
#include "Spawn_ByRandomAndTime.generated.h"

class UStaticMesh;
class UStaticMeshPoolBaseData;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USpawn_ByRandomAndTime : public UActorSpawner {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMeshPoolBaseData* StaticMeshPoolDA;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* RandomStaticMesh;
    
    USpawn_ByRandomAndTime();
};

