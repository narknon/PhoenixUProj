#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Templates/SubclassOf.h"
#include "HoverDroneConfigObject.generated.h"

class AActor;

UCLASS(Blueprintable)
class HOVERDRONE_API UHoverDroneConfigObject : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> m_HoverDroneControllerClass;
    
    UHoverDroneConfigObject();
};

