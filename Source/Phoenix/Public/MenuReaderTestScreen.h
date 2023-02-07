#pragma once
#include "CoreMinimal.h"
#include "Screen.h"
#include "MenuReaderTestScreen.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UMenuReaderTestScreen : public UScreen {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> ButtonStrings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> DummyPronunciationStrings;
    
    UMenuReaderTestScreen();
};

