#pragma once
#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "Cine_SkeletalMeshComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCine_SkeletalMeshComponent : public USkeletalMeshComponent {
    GENERATED_BODY()
public:
    UCine_SkeletalMeshComponent();
};

