#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InstancedTrailActorComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UInstancedTrailActorComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEditorOnly;
    
    UInstancedTrailActorComponent();
};

