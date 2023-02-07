#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CameraStackData.h"
#include "CameraStackSettings.generated.h"

class UCameraStackSettings;
class UObject;

UCLASS(Blueprintable)
class CAMERASTACK_API UCameraStackSettings : public UDataAsset {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCameraStackData StackData;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UCameraStackSettings*> StyleOverrides;
    
public:
    UCameraStackSettings();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    FCameraStackData GetStackData(const UObject* WorldContextObject) const;
    
};

