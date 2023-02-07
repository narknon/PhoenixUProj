#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UDSFieldGuideManager.generated.h"

class UUDSActivityManager;
class UUDSManager;

UCLASS(Blueprintable)
class UUDSFieldGuideManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUDSManager* UDSManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUDSActivityManager* UDSActivityManager;
    
public:
    UUDSFieldGuideManager();
};

