#pragma once
#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "BakedRagdollPoseComponent.generated.h"

class UBodySetup;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UBakedRagdollPoseComponent : public UPrimitiveComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UBodySetup* RagdollPoseBodySetup;
    
    UBakedRagdollPoseComponent();
};

