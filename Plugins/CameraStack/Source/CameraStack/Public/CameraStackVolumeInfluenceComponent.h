#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CameraStackVolumeInfluence.h"
#include "CameraStackVolumeInfluenceComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCameraStackVolumeInfluenceComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FCameraStackVolumeInfluence> Influences;
    
public:
    UCameraStackVolumeInfluenceComponent();
};

