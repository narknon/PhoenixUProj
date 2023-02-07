#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MultiplePoiTest.h"
#include "MultiplePoiTestsManager.generated.h"

UCLASS(Blueprintable, Config=AutomationTests)
class UMultiplePoiTestsManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMultiplePoiTest> AllTests;
    
    UMultiplePoiTestsManager();
};

