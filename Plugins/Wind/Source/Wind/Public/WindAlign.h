#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "WindAlign.generated.h"

class UWindAlignComponent;

UCLASS(Blueprintable)
class WIND_API AWindAlign : public AInfo {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWindAlignComponent* Component;
    
public:
    AWindAlign(const FObjectInitializer& ObjectInitializer);
};

