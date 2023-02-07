#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "CameraStackTarget.generated.h"

class AActor;

UCLASS(Blueprintable, DefaultToInstanced, EditInlineNew)
class CAMERASTACK_API UCameraStackTarget : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> TargetActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TargetSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector TargetOffset;
    
public:
    UCameraStackTarget();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWorldCamera() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetTargetVelocity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetTargetActor() const;
    
};

