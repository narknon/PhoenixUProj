#pragma once
#include "CoreMinimal.h"
#include "ActorSpawner.h"
#include "Templates/SubclassOf.h"
#include "Spawn_ByClass.generated.h"

class AActor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API USpawn_ByClass : public UActorSpawner {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> ActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* ActorTemplate;
    
    USpawn_ByClass();
};

