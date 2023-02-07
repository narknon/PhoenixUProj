#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "Actor_FromSpawner.generated.h"

class UActorSpawner;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UActor_FromSpawner : public UActorProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorSpawner* Spawner;
    
    UActor_FromSpawner();
};

