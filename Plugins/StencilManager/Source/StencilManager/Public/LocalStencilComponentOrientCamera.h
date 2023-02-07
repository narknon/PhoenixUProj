#pragma once
#include "CoreMinimal.h"
#include "LocalStencilComponent.h"
#include "LocalStencilComponentOrientCamera.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class STENCILMANAGER_API ULocalStencilComponentOrientCamera : public ULocalStencilComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MeshNearClipTweak;
    
    ULocalStencilComponentOrientCamera();
};

