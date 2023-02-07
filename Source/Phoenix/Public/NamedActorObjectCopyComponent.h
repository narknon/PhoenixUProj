#pragma once
#include "CoreMinimal.h"
#include "BaseObjectCopyComponent.h"
#include "NamedActorObjectCopyComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UNamedActorObjectCopyComponent : public UBaseObjectCopyComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ActorName;
    
    UNamedActorObjectCopyComponent();
};

