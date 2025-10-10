// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Image.h"
#include "Blueprint/WidgetTree.h"


UItemWidget::UItemWidget(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer)
{
	

}

void UItemWidget::NativeConstruct()
{
    Super::NativeConstruct();


}

void UItemWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

    if (SlotImage)
    {
        SlotImage = NewObject<UImage>(this);
        
    }
}
