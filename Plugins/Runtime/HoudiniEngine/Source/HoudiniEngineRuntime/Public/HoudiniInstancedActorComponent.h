#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "HoudiniInstancedActorComponent.generated.h"

class AActor;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class HOUDINIENGINERUNTIME_API UHoudiniInstancedActorComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SkipSerialization, meta=(AllowPrivateAccess=true))
    UObject* InstancedAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SkipSerialization, meta=(AllowPrivateAccess=true))
    TArray<AActor*> Instances;
    
    UHoudiniInstancedActorComponent();
};

