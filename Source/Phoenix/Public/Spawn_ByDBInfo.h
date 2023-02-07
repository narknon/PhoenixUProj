#pragma once
#include "CoreMinimal.h"
#include "ActorSpawner.h"
#include "DbSingleColumnInfo.h"
#include "SpawnSelectInfo.h"
#include "Templates/SubclassOf.h"
#include "Spawn_ByDBInfo.generated.h"

class AActor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API USpawn_ByDBInfo : public UActorSpawner {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnSelectInfo DBInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo CharacterLookIdInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> OverrideActorClass;
    
    USpawn_ByDBInfo();
};

