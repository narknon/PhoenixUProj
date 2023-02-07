#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "StudentCallOutAttachComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UStudentCallOutAttachComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UStudentCallOutAttachComponent();
};

