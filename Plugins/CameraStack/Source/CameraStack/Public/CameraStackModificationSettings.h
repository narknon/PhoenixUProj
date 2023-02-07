#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CameraStackModificationSettings.generated.h"

class UCameraStackOperationBase;

UCLASS(Blueprintable)
class CAMERASTACK_API UCameraStackModificationSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UCameraStackOperationBase*> StackOperations;
    
    UCameraStackModificationSettings();
};

