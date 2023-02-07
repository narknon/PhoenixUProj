#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SceneRigCameraParametersComponent.generated.h"

class USceneRigInstanceContext;
class USceneRigParameter;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USceneRigCameraParametersComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneRigInstanceContext> SceneRigInstanceContext;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FString, TWeakObjectPtr<USceneRigParameter>> Parameters;
    
    USceneRigCameraParametersComponent();
};

