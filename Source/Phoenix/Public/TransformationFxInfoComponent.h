#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "TransformationFxInfoComponent.generated.h"

class UBoxComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTransformationFxInfoComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* ObjectBounds;
    
    UTransformationFxInfoComponent();
};

