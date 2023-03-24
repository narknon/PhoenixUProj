#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HoudiniAssetActor.generated.h"

class UHoudiniAssetComponent;

UCLASS(Blueprintable)
class HOUDINIENGINERUNTIME_API AHoudiniAssetActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHoudiniAssetComponent* HoudiniAssetComponent;
    
    AHoudiniAssetActor(const FObjectInitializer& ObjectInitializer);
};

