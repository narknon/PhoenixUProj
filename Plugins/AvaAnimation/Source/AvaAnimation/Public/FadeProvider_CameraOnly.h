#pragma once
#include "CoreMinimal.h"
#include "FadeProvider.h"
#include "FadeProvider_CameraOnly.generated.h"

class APlayerCameraManager;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UFadeProvider_CameraOnly : public UFadeProvider {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APlayerCameraManager* PlayerCameraManager;
    
public:
    UFadeProvider_CameraOnly();
};

