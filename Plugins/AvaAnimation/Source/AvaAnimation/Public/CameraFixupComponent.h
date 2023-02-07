#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "CameraFixupComponent.generated.h"

class AActor;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class AVAANIMATION_API UCameraFixupComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* LastCameraFixupOperations;
    
    UCameraFixupComponent();
    UFUNCTION(BlueprintCallable)
    void LightRigBlueprintShowDebug(AActor* LightRigActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetTarget(bool& bOutHasValidTarget);
    
};

