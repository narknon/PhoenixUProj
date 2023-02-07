#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MountStreamingComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UMountStreamingComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowInteriorStreaming;
    
public:
    UMountStreamingComponent();
};

