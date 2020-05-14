# https://discord.com/oauth2/authorize?client_id=708638946179022878&scope=bot&permissions=8

import discord
import asyncio

token = open("token.txt", "r").read()

client = discord.Client()
Author = open("Author.txt", "r").read()
Friend = open("Author.txt", "r").read()
botcommandsid = int(open("botcommands.txt", "r").read())

@client.event  # event decorator/wrapper
async def on_ready():
    activity = discord.Activity(name='for 1000 members!', type=discord.ActivityType.watching)
    await client.change_presence(activity=activity, status=discord.Status.idle)
    print(f"Beep, boop. Logged in as {client.user}")


@client.event
async def on_message(msg):
    server = client.get_guild(523349543505362945)
    botcommands = client.get_channel(botcommandsid)
    if len(server.members) == 1004:
        await botcommands.send(f'{Author} {Friend}')
        await botcommands.send(f'We\'ve reached 1000 members! :tada:')
        await client.change_presence(status=discord.Status.invisible)
        await client.close()
        return
    if msg.author.bot or msg.content[0] != '$':
        return
    print(f'{msg.channel}: {msg.author}: {msg.author.name}: {msg.content}')
    cmd = msg.content[1:]
    if cmd == "exit":
        if msg.channel == botcommands:
            await botcommands.send(f'{Author}')
            await botcommands.send('Going offline. See ya!')
            await client.change_presence(status=discord.Status.invisible)
            await client.close()
        else:
            await msg.channel.send(f'Incorrect channel, {msg.author.name}, please use #bot-commands to turn off the bot.')
        return
    elif cmd == "members":
        await msg.channel.send(f'Hi, {msg.author.name}! Current member count (with bots):')
        await msg.channel.send(len(server.members))
        return
    elif cmd == "engie":
        await msg.channel.send("Hey look, buddy, I'm an Engineer. That means I solve problems.\nNot problems like \"What is beauty?\", because that would fall within the purview of your conundrums of philosophy.")
        await asyncio.sleep(2)
        await msg.channel.send("I solve practical problems.")
        await asyncio.sleep(2)
        await msg.channel.send("Fr'instance...")
        await asyncio.sleep(2)
        await msg.channel.send("...How am I going to stop some big mean mother hubbard from tearing me a structurally superfluous new behind?\nThe answer...")
        await asyncio.sleep(2)
        await msg.channel.send("...use a gun. And if that don't work...\n...use more gun.")
        await asyncio.sleep(2)
        await msg.channel.send("Like this heavy caliber, tripod-mounted, little ol' number designed by me...")
        await asyncio.sleep(2)
        await msg.channel.send("...Built by me...")
        await asyncio.sleep(2)
        await msg.channel.send("...and you'd best hope...")
        await asyncio.sleep(5)
        await msg.channel.send("not pointed at you.")
        return

if __name__ == '__main__':
    secret = ''
    client.run(token)
