#pragma once
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "ShadowBoxComponent.generated.h"

class ADoor;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UShadowBoxComponent : public UStaticMeshComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseForBothSidesOfTheDoor;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ADoor* Door;
    
public:
    UShadowBoxComponent();
};

